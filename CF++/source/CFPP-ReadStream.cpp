/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        CFPP-ReadStream.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFReadStreamRef wrapper
 */

#include <CF++.hpp>

namespace CF
{
    ReadStream::ReadStream( void ): _cfObject( NULL )
    {}
    
    ReadStream::ReadStream( URL url )
    {
        this->_cfObject = CFReadStreamCreateWithFile( static_cast< CFAllocatorRef >( NULL ), url );
    }
    
    ReadStream::ReadStream( std::string path )
    {
        URL url;
        
        url = URL::FileSystemURL( path );
        
        this->_cfObject = CFReadStreamCreateWithFile( static_cast< CFAllocatorRef >( NULL ), url );
    }
    
    ReadStream::ReadStream( const char * path )
    {
        URL url;
        
        url = URL::FileSystemURL( path );
        
        this->_cfObject = CFReadStreamCreateWithFile( static_cast< CFAllocatorRef >( NULL ), url );
    }
    
    ReadStream::ReadStream( const ReadStream & value )
    {
        if( value._cfObject != NULL )
        {
            this->_cfObject = static_cast< CFReadStreamRef >( const_cast< void * >( CFRetain( value._cfObject ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    ReadStream::ReadStream( CFTypeRef value )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFReadStreamRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    ReadStream::ReadStream( CFReadStreamRef value )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFReadStreamRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    #ifdef CFPP_HAS_CPP11
    ReadStream::ReadStream( ReadStream && value )
    {
        this->_cfObject = value._cfObject;
        value._cfObject = NULL;
    }
    #endif
    
    ReadStream::~ReadStream( void )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
            
            this->_cfObject = NULL;
        }
    }
    
    ReadStream & ReadStream::operator = ( ReadStream value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    ReadStream & ReadStream::operator = ( CFTypeRef value )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFReadStreamRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
        
        return *( this );
    }
    
    ReadStream & ReadStream::operator = ( CFReadStreamRef value )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFReadStreamRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
        
        return *( this );
    }
    
    CFTypeID ReadStream::GetTypeID( void ) const
    {
        return CFReadStreamGetTypeID();
    }
    
    CFTypeRef ReadStream::GetCFObject( void ) const
    {
        return this->_cfObject;
    }
    
    bool ReadStream::Open( void ) const
    {
        if( this->_cfObject == NULL )
        {
            return false;
        }
        
        return ( CFReadStreamOpen( this->_cfObject ) ) ? true : false;
    }
    
    bool ReadStream::Open( std::string path )
    {
        return this->Open( URL::FileSystemURL( path ) );
    }
    
    bool ReadStream::Open( const char * path )
    {
        return this->Open( URL::FileSystemURL( path ) );
    }
    
    bool ReadStream::Open( URL url )
    {
        if( this->_cfObject != NULL )
        {
            this->Close();
            
            CFRelease( this->_cfObject );
        }
        
        this->_cfObject = CFReadStreamCreateWithFile( static_cast< CFAllocatorRef >( NULL ), url );
        
        return this->Open();
    }
    
    void ReadStream::Close( void ) const
    {
        if( this->_cfObject == NULL )
        {
            return;
        }
        
        CFReadStreamClose( this->_cfObject );
    }
    
    bool ReadStream::HasBytesAvailable( void ) const
    {
        if( this->_cfObject == NULL )
        {
            return false;
        }
        
        return ( CFReadStreamHasBytesAvailable( this->_cfObject ) ) ? true : false;
    }
    
    CFStreamStatus ReadStream::GetStatus( void ) const
    {
        if( this->_cfObject == NULL )
        {
            return kCFStreamStatusError;
        }
        
        return CFReadStreamGetStatus( this->_cfObject );
    }
    
    Error ReadStream::GetError( void ) const
    {
        AutoPointer e;
        
        if( this->_cfObject == NULL )
        {
            return e.As< CFErrorRef >();
        }
        
        e = CFReadStreamCopyError( this->_cfObject );
        
        return e.As< CFErrorRef >();
    }
        
    CFIndex ReadStream::Read( Data::Byte * buffer, CFIndex length ) const
    {
        if( this->_cfObject == NULL )
        {
            return 0;
        }
        
        if( buffer == NULL || length <= 0 )
        {
            return 0;
        }
        
        return CFReadStreamRead( this->_cfObject, buffer, length );
    }
    
    Data ReadStream::Read( CFIndex length ) const
    {
        Data         data;
        Data::Byte * bytes;
        CFIndex      read;
        
        if( this->_cfObject == NULL )
        {
            return data;
        }
        
        if( length > 0 )
        {
            bytes = new Data::Byte[ length ];
            read  = this->Read( bytes, length );
            
            if( read > 0 )
            {
                data.AppendBytes( bytes, read );
            }
        }
        else
        {
            bytes = new Data::Byte[ 4096 ];
            
            while( this->HasBytesAvailable() )
            {
                read = this->Read( bytes, 4096 );
                
                if( read > 0 )
                {
                    data.AppendBytes( bytes, read );
                }
            }
        }
        
        delete[] bytes;
        
        return data;
    }
    
    const Data::Byte * ReadStream::GetBuffer( CFIndex maxBytesToRead, CFIndex * numBytesRead ) const
    {
        if( this->_cfObject == NULL )
        {
            return NULL;
        }
        
        return CFReadStreamGetBuffer( this->_cfObject, maxBytesToRead, numBytesRead );
    }
    
    AutoPointer ReadStream::GetProperty( String name )
    {
        if( this->_cfObject == NULL )
        {
            return NULL;
        }
        
        return CFReadStreamCopyProperty( this->_cfObject, name );
    }
    
    bool ReadStream::SetProperty( String name, CFTypeRef value )
    {
        if( this->_cfObject == NULL )
        {
            return false;
        }
        
        return CFReadStreamSetProperty( this->_cfObject, name, value );
    }
    
    void ReadStream::SetClient( CFOptionFlags events, CFReadStreamClientCallBack callback, CFStreamClientContext * context )
    {
        if( this->_cfObject == NULL )
        {
            return;
        }
        
        CFReadStreamSetClient( this->_cfObject, events, callback, context );
    }
    
    ReadStream::Iterator ReadStream::begin( CFIndex bytesToRead ) const
    {
        return Iterator( this->_cfObject, bytesToRead );
    }
    
    ReadStream::Iterator ReadStream::end( void ) const
    {
        Iterator i( this->_cfObject, 0 );
        
        i._end = true;
        
        return i;
    }
    
    void swap( ReadStream & v1, ReadStream & v2 )
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
    }
}
