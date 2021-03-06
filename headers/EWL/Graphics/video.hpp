#pragma once

#include <EWL/Graphics/pixmap.hpp>
#include <EWL/System/Compression/compressors.hpp>

#include <vector>

namespace ewl {
    class Video {
        private:
            uint32_t framesPerSecond;
            std::vector<Pixmap> frames;
            Compressor* compressor;
            bool c_deletable;
            

        public:
            /*Gets frames pointer*/

            Pixmap* getFramesPtr() const;

            /*Gets frame from videon on the position*/

            Pixmap* getFrame(uint32_t num) const;

            /*Adds frame to video*/

            bool addFrame(const Pixmap& pixmap);

            /*Removes frame from video*/

            bool deleteFrame(uint32_t num);
            
            /*Exports the movie*/

            bool exportToMP4(const char* path) const;
            bool exportToMKV(const char* path) const;
            bool exportToWMV(const char* path) const;
            bool exportToGIF(const char* path) const;

            /*Imports the movie*/

            bool loadFromMP4(const char* path);
            bool loadFromMKV(const char* path);
            bool loadFromWMV(const char* path);
            bool loadFromGIF(const char* path);

            /*Sets compressor*/

            void setCompressor(Compressor* comp, bool deletable = true);

            /*Gets compressor*/

            Compressor* getCompressor() const;

            /*Compress the movie*/

            bool compress(int32_t s_frames = 0, int32_t e_frames = -1);

            /*Decompress the movie*/

            bool decompress(int32_t s_frames = 0, int32_t e_frames = -1);
    };
}
