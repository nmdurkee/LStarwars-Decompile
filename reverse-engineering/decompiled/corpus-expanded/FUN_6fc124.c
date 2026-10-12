/* Ghidra pseudocode, not original source.
 * ev_626d54f17f079edfd1ff8b6caea4a3c32539f18361fa5c980ebe5ce2dfd8aaf4
 * Entry: 0x6fc124; label: _isleadbyte
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _isleadbyte
   
   Library: Visual Studio 2005 Release */

int __cdecl _isleadbyte(int _C)

{
  int iVar1;
  
  iVar1 = __isleadbyte_l(_C,(_locale_t)0x0);
  return iVar1;
}

