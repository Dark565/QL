objdir=Build
libdir=QL

libs=-ltiff -lpng -ljpeg -ldl
qlobjs=$(objdir)/pixmap.o $(objdir)/images.o $(objdir)/colors.o $(objdir)/console.o $(objdir)/tiff.o $(objdir)/png.o $(objdir)/jpeg.o $(objdir)/maths.o $(objdir)/video.o $(objdir)/vgif.o $(objdir)/vmkv.o $(objdir)/vmp4.o $(objdir)/vwmv.o $(objdir)/system.o $(objdir)/time.o
qllibs=-lql-pixmap -ql-console -ql-images -ql-maths -lql-video -lql-system 

all: make_static_program

libs:
	g++ -shared $(objdir)/pixmap.o $(objdir)/tiff.o $(objdir)/png.o $(objdir)/jpeg.o -o $(objdir)/libql-pixmap.so $(libs) -Wall
	g++ -shared $(objdir)/colors.o -o $(objdir)/libql-colors.so -Wall
	g++ -shared $(objdir)/console.o -o $(objdir)/libql-console.so -Wall
	g++ -shared $(objdir)/images.o -o $(objdir)/libql-images.so -Wall
	g++ -shared $(objdir)/maths.o -o $(objdir)/libql-maths.so -Wall
	g++ -shared $(objdir)/video.o $(objdir)/vgif.o $(objdir)/vmkv.o $(objdir)/vmp4.o $(objdir)/vwmv.o -o $(objdir)/libql-video.so -lavcodec -I/usr/include/ffmpeg/ -Wall
	g++ -shared $(objdir)/system.o $(objdir)/time.o -o $(objdir)/libql-system.so -Wall

compile:
	g++ -fPIC -c $(libdir)/Pixmap/pixmap.cpp -o $(objdir)/pixmap.o -Wall
	g++ -fPIC -c $(libdir)/Images/images.cpp -o $(objdir)/images.o -Wall
	g++ -fPIC -c $(libdir)/Colorize/colors.cpp -o $(objdir)/colors.o -Wall
	g++ -fPIC -c $(libdir)/Console/console.cpp -o $(objdir)/console.o -Wall
	g++ -fPIC -c $(libdir)/Pixmap/IO/tiff.cpp -o $(objdir)/tiff.o -Wall
	g++ -fPIC -c $(libdir)/Pixmap/IO/png.cpp -o $(objdir)/png.o -Wall
	g++ -fPIC -c $(libdir)/Pixmap/IO/jpeg.cpp -o $(objdir)/jpeg.o -Wall
	g++ -fPIC -c $(libdir)/Maths/maths.cpp -o $(objdir)/maths.o -Wall
	g++ -fPIC -c $(libdir)/Video/video.cpp -o $(objdir)/video.o -Wall
	g++ -fPIC -c $(libdir)/Video/IO/gif.cpp -o $(objdir)/vgif.o -Wall -I/usr/include/ffmpeg
	g++ -fPIC -c $(libdir)/Video/IO/mkv.cpp -o $(objdir)/vmkv.o -Wall -I/usr/include/ffmpeg
	g++ -fPIC -c $(libdir)/Video/IO/mp4.cpp -o $(objdir)/vmp4.o -Wall -I/usr/include/ffmpeg
	g++ -fPIC -c $(libdir)/Video/IO/wmv.cpp -o $(objdir)/vwmv.o -Wall -I/usr/include/ffmpeg
	g++ -fPIC -c $(libdir)/System/system.cpp -o $(objdir)/system.o -Wall
	g++ -fPIC -c $(libdir)/Time/units.cpp -o $(objdir)/time.o -Wall

make_dyn_program:
	g++ main.cpp -o ql -L$(objdir) $(qllibs) -Wall -Wl,-rpath=$(objdir)

make_static_program:
	g++ main.cpp $(qlobjs) $(libs) -o ql 

