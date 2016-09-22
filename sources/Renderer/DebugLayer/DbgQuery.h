/*
 * DbgQuery.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_DBG_QUERY_H__
#define __LLGL_DBG_QUERY_H__


#include <LLGL/Query.h>


namespace LLGL
{


class DbgQuery : public Query
{

    public:

        enum class State
        {
            Uninitialized,
            Busy,
            Ready,
        };

        DbgQuery(Query& instance, QueryType type) :
            Query   ( type     ),
            instance( instance )
        {
        }

        Query&  instance;
        State   state   = State::Uninitialized;

};


} // /namespace LLGL


#endif



// ================================================================================