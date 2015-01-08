#ifndef wesnoth_data_nodeFlexLexer_HPP_INCLUDED
#define wesnoth_data_nodeFlexLexer_HPP_INCLUDED 1


/**
   wesnoth_data_nodeFlexLexer is an auto-generated class and is NOT part of the
   public s11n or s11n::io APIs. It is an implementation detail only,
   but is installed along with the rest of the headers so that we can
   build s11n on platforms where the 'flex' tool is not available to
   generate this class' underlying code, provided thoses platforms can
   build the code generated by flex on another platform (which should
   work for most platforms, in theory).

   See the FlexLexer class for the interface documentation.
*/
class wesnoth_data_nodeFlexLexer : public FlexLexer {
public:
        // arg_yyin and arg_yyout default to the cin and cout, but we
        // only make that assignment when initializing in yylex().
        wesnoth_data_nodeFlexLexer( istream* arg_yyin = 0, ostream* arg_yyout = 0 );

        virtual ~wesnoth_data_nodeFlexLexer();

        void yy_switch_to_buffer( struct yy_buffer_state* new_buffer );
        struct yy_buffer_state* yy_create_buffer( istream* s, int size );
        void yy_delete_buffer( struct yy_buffer_state* b );
        void yyrestart( istream* s );

        virtual int yylex();
        virtual void switch_streams( istream* new_in, ostream* new_out );

        int yylex( istream* new_in, ostream* new_out = 0 ) {
          // see Frank's notes in FlexLexer.hpp for why yylex() is implemented this way.
          return FlexLexer::yylex(new_in, new_out);
        }

protected:
        virtual int LexerInput( char* buf, int max_size );
        virtual void LexerOutput( const char* buf, int size );
        virtual void LexerError( const char* msg );

        // Function that can be used by subclasses during yylex()
        virtual int actionHook(void* data = 0) {
          return data == 0;
        }

        void yyunput( int c, char* buf_ptr );
        int yyinput();

        void yy_load_buffer_state();
        void yy_init_buffer( struct yy_buffer_state* b, istream* s );
        void yy_flush_buffer( struct yy_buffer_state* b );

        int yy_start_stack_ptr;
        int yy_start_stack_depth;
        int* yy_start_stack;

        void yy_push_state( int new_state );
        void yy_pop_state();
        int yy_top_state();

        yy_state_type yy_get_previous_state();
        yy_state_type yy_try_NUL_trans( yy_state_type current_state );
        int yy_get_next_buffer();

        istream* yyin;  // input source for default LexerInput
        ostream* yyout; // output sink for default LexerOutput

        struct yy_buffer_state* yy_current_buffer;

        // yy_hold_char holds the character lost when yytext is formed.
        char yy_hold_char;

        // Number of characters read into yy_ch_buf.
        int yy_n_chars;

        // Points to current character in buffer.
        char* yy_c_buf_p;

        int yy_init;            // whether we need to initialize
        int yy_start;           // start state number

        // Flag which is used to allow yywrap()'s to do buffer switches
        // instead of setting up a fresh yyin.  A bit of a hack ...
        int yy_did_buffer_switch_on_eof;

        // The following are not always needed, but may be depending
        // on use of certain flex features (like REJECT or yymore()).

        yy_state_type yy_last_accepting_state;
        char* yy_last_accepting_cpos;

        yy_state_type* yy_state_buf;
        yy_state_type* yy_state_ptr;

        char* yy_full_match;
        int* yy_full_state;
        int yy_full_lp;

        int yy_lp;
        int yy_looking_for_trail_begin;

        int yy_more_flag;
        int yy_more_len;
        int yy_more_offset;
        int yy_prev_more_offset;
};

#endif // wesnoth_data_nodeFlexLexer_HPP_INCLUDED

