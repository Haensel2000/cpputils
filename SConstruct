import os;
import os.path;

include_path = [
  '#src'
]

lib_path = [
]

libs = [
]

ccflags = '-O0 -g3 -Wall -c -fmessage-length=0'

source_files = ['#' + os.path.join(r,f).replace('src', 'build') for r,d,fs in os.walk('src') for f in fs if f.endswith('.cpp')]

env = Environment(CC = 'g++',
                  CPPPATH = include_path, 
                  LIBPATH=lib_path, 
                  LIBS=libs, 
                  CCFLAGS=ccflags,
                  source_files=source_files)   
VariantDir('build', 'src', duplicate=0)            

env.StaticLibrary(target='build/cpputils', source=source_files)

Clean('.', 'build')