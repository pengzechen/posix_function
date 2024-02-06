import os 
import subprocess

files = os.listdir("res")
for file in files:
    file_path = os.path.join("res", file)
    if ".c" not in file_path:   #  运行bin文件
        print('---------------------', file_path, '--------------------------')
        file = 'strace_file/'+file_path.split('.')[0]+'.txt'
        print(file)
        result = subprocess.run( ['strace', '-o' , file,
                                 file_path.split('.')[0],], 

                                 stdout = subprocess.PIPE, 
                                 stderr = subprocess.PIPE)
        
        try:
            print(result.stdout.decode('gbk'))
        except:
            print(result.stdout)

"""
sudo pkill pause || sudo pkill pthread_sigmask -9 || sudo pkill sigaction ||\
sudo pkill sigaddset || sudo pkill sigemptyset || sudo pkill sigfillset -9 ||\
sudo pkill signal || sudo pkill sigsuspend || sudo pkill sigwait
"""