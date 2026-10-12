/* Ghidra analysis pseudocode, not original source.
 * ev_0c181eace2d19d4182fe88edb7c380dbd0b0bf6e152acc5799b1564533e0f6fc
 * Entry: 0x6ec18b; label: __init_pointers
 */

/* Library Function - Single Match
    __init_pointers
   
   Library: Visual Studio 2005 Release */

void __cdecl __init_pointers(void)

{
  undefined4 uVar1;
  
  uVar1 = __encoded_null();
  FUN_006f28b4(uVar1);
  FUN_006fd019(uVar1);
  FUN_006e9e84(uVar1);
  FUN_006f4eb3(uVar1);
  FUN_006fcf0b(uVar1);
  __initp_misc_winsig(uVar1);
  FUN_006f0bf1(uVar1);
  __initp_eh_hooks(uVar1);
  PTR___exit_00829a68 = (undefined *)FUN_006f0145(__exit);
  return;
}

