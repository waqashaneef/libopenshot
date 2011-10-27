#ifndef OPENSHOT_EXCEPTIONS_H
#define OPENSHOT_EXCEPTIONS_H

/**
 * \file
 * \brief Header file for all Exception classes
 * \author Copyright (c) 2011 Jonathan Thomas
 */

#include <cstring>

using namespace std;

namespace openshot {

	/**
	 * \brief Base exception class with a custom message variable.
	 *
	 * A custom error message field has been added to the std::exception base class.  All
	 * OpenShot exception classes inherit from this class.
	 */
	class BaseException //: public exception
	{
	protected:
		string m_message;
	public:
		BaseException(string message) : m_message(message) { }
		virtual ~BaseException() throw () {}
		virtual const char* what() const throw () {
			// return custom message
			return m_message.c_str();
		}
	};

	/// Exception for frames that are out of bounds.
	class OutOfBoundsFrame : public BaseException
	{
	public:
		int FrameRequested;
		int MaxFrames;
		OutOfBoundsFrame(string message, int frame_requested, int max_frames)
			: BaseException(message), FrameRequested(frame_requested), MaxFrames(max_frames) { }
		virtual ~OutOfBoundsFrame() throw () {}
	};

	/// Exception for an out of bounds key-frame point.
	class OutOfBoundsPoint : public BaseException
	{
	public:
		int PointRequested;
		int MaxPoints;
		OutOfBoundsPoint(string message, int point_requested, int max_points)
			: BaseException(message), PointRequested(point_requested), MaxPoints(max_points) { }
		virtual ~OutOfBoundsPoint() throw () {}
	};

	/// Exception for files that can not be found or opened
	class InvalidFile : public BaseException
	{
	public:
		string file_path;
		InvalidFile(string message, string file_path)
			: BaseException(message), file_path(file_path) { }
		virtual ~InvalidFile() throw () {}
	};

	/// Exception when no streams are found in the file
	class NoStreamsFound : public BaseException
	{
	public:
		string file_path;
		NoStreamsFound(string message, string file_path)
			: BaseException(message), file_path(file_path) { }
		virtual ~NoStreamsFound() throw () {}
	};

	/// Exception when no valid codec is found for a file
	class InvalidCodec : public BaseException
	{
	public:
		string file_path;
		InvalidCodec(string message, string file_path)
			: BaseException(message), file_path(file_path) { }
		virtual ~InvalidCodec() throw () {}
	};

	/// Exception when decoding audio packet
	class ErrorDecodingAudio : public BaseException
	{
	public:
		string file_path;
		int frame_number;
		ErrorDecodingAudio(string message, int frame_number)
			: BaseException(message), frame_number(frame_number) { }
		virtual ~ErrorDecodingAudio() throw () {}
	};

}

#endif