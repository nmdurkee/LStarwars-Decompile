/* Ghidra pseudocode, not original source.
 * ev_626d54f17f079edfd1ff8b6caea4a3c32539f18361fa5c980ebe5ce2dfd8aaf4
 * Entry: 0x6fadc3; label: __copytlocinfo_nolock
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __copytlocinfo_nolock
   
   Library: Visual Studio 2005 Release */

void __copytlocinfo_nolock(void)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  if (((in_ECX != (undefined4 *)0x0) && (in_EAX != (undefined4 *)0x0)) && (in_EAX != in_ECX)) {
    puVar2 = in_EAX;
    for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *in_ECX;
      in_ECX = in_ECX + 1;
      puVar2 = puVar2 + 1;
    }
    *in_EAX = 0;
    ___addlocaleref();
  }
  return;
}

