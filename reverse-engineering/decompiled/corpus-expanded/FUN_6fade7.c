/* Ghidra pseudocode, not original source.
 * ev_626d54f17f079edfd1ff8b6caea4a3c32539f18361fa5c980ebe5ce2dfd8aaf4
 * Entry: 0x6fade7; label: __updatetlocinfoEx_nolock
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __updatetlocinfoEx_nolock
   
   Library: Visual Studio 2005 Release */

int * __updatetlocinfoEx_nolock(void)

{
  int *piVar1;
  undefined4 *in_EAX;
  int *unaff_EDI;
  
  if ((unaff_EDI != (int *)0x0) && (in_EAX != (undefined4 *)0x0)) {
    piVar1 = (int *)*in_EAX;
    if (piVar1 != unaff_EDI) {
      *in_EAX = unaff_EDI;
      ___addlocaleref();
      if (piVar1 != (int *)0x0) {
        ___removelocaleref(piVar1);
        if ((*piVar1 == 0) && (piVar1 != (int *)&DAT_0082a5a0)) {
          ___freetlocinfo(piVar1);
        }
      }
    }
    return unaff_EDI;
  }
  return (int *)0x0;
}

