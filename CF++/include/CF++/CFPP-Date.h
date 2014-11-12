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
 
/* $Id$ */

/*!
 * @header      CFPP-Date.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFDateRef wrapper
 */

#ifndef __CFPP_DATE_H__
#define __CFPP_DATE_H__

#include <CF++/CFPP-PropertyListType.h>

namespace CF
{
    class Date: public PropertyListType< Date >
    {
        public:
            
            static Date CurrentDate( void );
            
            Date( void );
            Date( const Date & value );
            Date( CFTypeRef value );
            Date( CFDateRef value );
            Date( CFAbsoluteTime value );
            
            virtual ~Date( void );
            
            Date & operator = ( const Date value );
            Date & operator = ( CFTypeRef value );
            Date & operator = ( CFDateRef value );
            Date & operator = ( CFAbsoluteTime value );
            
            bool operator == ( const Date & value ) const;
            bool operator == ( CFTypeRef value ) const;
            bool operator == ( CFDateRef value ) const;
            bool operator == ( CFAbsoluteTime value ) const;
            
            bool operator != ( const Date & value ) const;
            bool operator != ( CFTypeRef value ) const;
            bool operator != ( CFDateRef value ) const;
            bool operator != ( CFAbsoluteTime value ) const;
            
            bool operator >= ( const Date & value ) const;
            bool operator >= ( CFDateRef value ) const;
            bool operator >= ( CFAbsoluteTime value ) const;
            
            bool operator <= ( const Date & value ) const;
            bool operator <= ( CFDateRef value ) const;
            bool operator <= ( CFAbsoluteTime value ) const;
            
            bool operator > ( const Date & value ) const;
            bool operator > ( CFDateRef value ) const;
            bool operator > ( CFAbsoluteTime value ) const;
            
            bool operator < ( const Date & value ) const;
            bool operator < ( CFDateRef value ) const;
            bool operator < ( CFAbsoluteTime value ) const;
            
            Date & operator += ( const Date & value );
            Date & operator += ( CFDateRef value );
            Date & operator += ( CFAbsoluteTime value );
            
            Date & operator -= ( const Date & value );
            Date & operator -= ( CFDateRef value );
            Date & operator -= ( CFAbsoluteTime value );
            
            Date operator + ( const Date & value );
            Date operator + ( CFDateRef value );
            Date operator + ( CFAbsoluteTime value );
            
            Date operator - ( const Date & value );
            Date operator - ( CFDateRef value );
            Date operator - ( CFAbsoluteTime value );
            
            Date & operator ++ ( void );
            Date   operator ++ ( int );
            Date & operator -- ( void );
            Date   operator -- ( int );
            
            operator CFAbsoluteTime ();
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            CFAbsoluteTime GetValue( void ) const;
            void           SetValue( CFAbsoluteTime value );
            
            friend void swap( Date & v1, Date & v2 );
            
        protected:
            
            CFDateRef _cfObject;
    };
}

#endif /* __CFPP_DATE_H__ */
