#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<io.h>
#include<string>
#include<vector>
#include<windows.h>
using namespace std;
vector<string> versions;
vector<string> find_target;
void getAllFiles(string path) {
	  int i=0;
	  int a=0;
	  bool fn;
      long hFile = 0;
      struct _finddata_t fileinfo;
      string p;
      string temp;
      if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) != -1) {
          do {
              if ((fileinfo.attrib & _A_SUBDIR)) {
                 if (strcmp(fileinfo.name,".") != 0 && strcmp(fileinfo.name,"..") != 0) {
                     temp=p.assign(path).append("\\").append(fileinfo.name);
                     i++;
					 if(temp.find(".minecraft")!=string::npos){
					 	fn=false;
					 	if(find_target.size()!=0){
					 		for(a=0;a<find_target.size();a++)
					 			if(temp.find(find_target[a])!=string::npos)
					 				fn=true;
						}
					 }
					 else
					 	fn=true;
					if(!fn) find_target.push_back(temp);
                     if(i==20){
                     	system("cls");
                     	cout<<temp<<endl;
						cout<<"����ɨ�����.minecraft�ļ���...\n�������Ҫ������ʱ�䡣\n���ҵ�"<<find_target.size()<<"��.minecraft�ļ��С�"<<endl;
						i=0;
					 }
                     getAllFiles(p.assign(path).append("\\").append(fileinfo.name));
                 }
             } else {
                 temp=p.assign(path).append("\\").append(fileinfo.name);
             }
         } while (_findnext(hFile, &fileinfo) == 0);
         _findclose(hFile);
     }
}

void getJustCurrentDir(string path, vector<string>& files){
    long hFile = 0;
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) != -1) {
        do {  
            if ((fileinfo.attrib & _A_SUBDIR)) {  
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
                    files.push_back(fileinfo.name);
                }
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}


int main()
{
	system("title MCleaner");
	char *pathvar;
	int inp;
	int a1,a2;
	srand(time(0));
	cout<<"MCleaner v1.0\nBy MineCommander\n====================\n";
	cout<<"��ѡ������ģʽ��\n[1]��������������.minecraft�ļ���\n[2]�Զ���ɨ��.minecraft�ļ���\n[3]�ֶ�ָ��.minecraftĿ¼\n>>>";
	string path;
	string tmp;
	cin>>inp;
	system("cls");
	if(inp==1){
		pathvar = getenv("APPDATA");
		path=pathvar;
		path+="\\.minecraft";
	}
		
	if(inp==2){
		cout<<"��������Ҫɨ���·����\n>>>";
		cin>>path;
		getAllFiles(path);
		system("cls");
		if(find_target.size()>0){
			cout<<"�Ѿ��ҵ�"<<find_target.size()<<"��.minecraft�ļ��У�\n";
			for(int i=0;i<find_target.size();i++)
				cout<<"["<<i+1<<"]"<<find_target[i]<<endl;
			cout<<endl<<"��������Ҫ�����.minecraft�ļ��е���ţ�\n>>>";
			cin>>inp;
			path=find_target[inp-1];
			inp=32767;
		}
		else{
			cout<<"Ohhops,����δ����ָ��Ŀ¼���ҵ�.minecraft�ļ��У��������Ŀ¼���벻��ȷ��\n�볢������ģʽ�����ǻ���Ŀ¼���ԡ�\n";
			system("pause");
			return 0;
		}
	}
	if(inp==3){
		cout<<"���������.minecraftĿ¼λ�ã�\n>>>";
		cin>>path;
	}
	system("cls");
	cout<<"��ѡ�е�.minecraftĿ¼��"<<path<<endl;
	cout<<"����Ŀ¼�Ƿ�ʹ���˰汾���룿\n[1]��\n[2]��\n>>>";
	cin>>inp;
	if(inp==1){
		system("cls");
		cout<<"���Եȣ���������ɨ��汾Ŀ¼...";
		getJustCurrentDir(path+"\\versions",versions);
		system("cls");
		cout<<path<<"�������°汾Ŀ¼��\n";
		for(int i=0;i<versions.size();i++)
			cout<<"["<<i+1<<"]"<<versions[i]<<endl;
		cout<<"��������Ҫ����İ汾��ţ�\n>>>";
		cin>>inp;
		path=path+"\\versions\\"+versions[inp-1];
		inp=2;
	}
	if(inp==2){
		system("cls");
		cout<<"���򼴽�ɾ�������ļ����е�ȫ�����ݣ�"<<endl;
		cout<<"    "+path+"\\logs(��־�ļ�)"<<endl;
		cout<<"    "+path+"\\crash-reports(��������)"<<endl;
		cout<<"    "+path+"\\screenshots(��Ϸ��ͼ)"<<endl;
		cout<<"    "+path+"\\debugs(���Ա���)"<<endl;
		cout<<"    "+path+"\\server-resource-packs(�ӷ��������ص���Դ��)"<<endl;
		cout<<"��ش�������ȷ�ϣ�"<<(a1=rand()%10+1)<<'+'<<(a2=rand()%10+1)<<'=';
		cin>>inp;
		if(inp==a1+a2){
			system("cls");
			cout<<"�����������Ժ�...\n";
			tmp="del /Q "+path+"\\logs";
			system(tmp.c_str());
			tmp="del /Q "+path+"\\crash-reports";
			system(tmp.c_str());
			tmp="del /Q "+path+"\\screenshots";
			system(tmp.c_str());
			tmp="del /Q "+path+"\\debugs";
			system(tmp.c_str());
			tmp="del /Q "+path+"\\server-resource-packs";
			system(tmp.c_str());
			cout<<endl<<"��������ɣ�";
			system("pause");
		}
	}
}
