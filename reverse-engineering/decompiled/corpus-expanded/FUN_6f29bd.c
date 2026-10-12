/* Ghidra pseudocode, not original source.
 * ev_8db3786b1d2e9370d3feb832809c6ae27354528dfff9c38ddb75cfb6eefed4ac
 * Entry: 0x6f29bd; label: __ftbuf
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __ftbuf
   
   Library: Visual Studio 2005 Release */

void __cdecl __ftbuf(int _Flag,FILE *_File)

{
  if ((_Flag != 0) && ((_File->_flag & 0x1000) != 0)) {
    __flush(_File);
    _File->_flag = _File->_flag & 0xffffeeff;
    _File->_bufsiz = 0;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
  }
  return;
}

