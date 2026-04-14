#ifndef _CPPHELPER_H
#define _CPPHELPER_H


#define NO_COPY_NO_MOVE(CLASS) \
CLASS(const CLASS&) = delete; \
CLASS(      CLASS&&) = delete; \
CLASS& operator=(const CLASS&) = delete; \
CLASS& operator=(      CLASS&&) = delete

#endif
