/* Ghidra analysis pseudocode, not original source.
 * ev_fecaad0f39b6546b4dc9650dce16c9bbcd2a84d15696a82d10463b768249874c
 * Entry: 0x6ee9f9; label: __cfltcvt
 */

/* Library Function - Single Match
    __cfltcvt
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release,
   Visual Studio 2012 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  errno_t eVar1;
  
  eVar1 = __cfltcvt_l(arg,buffer,sizeInBytes,format,precision,caps,(_locale_t)0x0);
  return eVar1;
}

