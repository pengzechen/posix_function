import os 
import subprocess

files = os.listdir("res")
for file in files:
    file_path = os.path.join("res", file)
    # print(file_path)
    if ".c" in file_path:   #  编译 .c 文件
        result = subprocess.run(['gcc', 
                                 '-g', 
                                 file_path, 
                                 '-lpthread',
                                 '-lm',
                                 '-o', file_path.split('.')[0]], 
                                 stdout = subprocess.PIPE, 
                                 stderr = subprocess.PIPE)
        try:
            print(result.stderr.decode())
        except:
            print(result.stderr)
        
        subprocess.run(['chmod', '+x', file_path.split('.')[0]])
        
        print("-----------------------------", file_path, "-----------------------------")
        
