/* Ghidra analysis pseudocode, not original source.
 * ev_0c181eace2d19d4182fe88edb7c380dbd0b0bf6e152acc5799b1564533e0f6fc
 * Entry: 0x6ebd99; label: __amsg_exit
 */

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2005 Release */

void __cdecl __amsg_exit(int param_1)

{
  code *pcVar1;
  
  __FF_MSGBANNER();
  FUN_006f09f8(param_1);
  pcVar1 = (code *)FUN_006f01bc(PTR___exit_00829a68);
  (*pcVar1)(0xff);
  return;
}

