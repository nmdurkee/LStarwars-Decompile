/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x749390; label: FUN_00749390
 */

bool FUN_00749390(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00748bf0(param_1,param_2,in_ECX + 0xbb0,0x5000,in_ECX + 0xbc0);
  *(int *)(in_ECX + 0x208) = iVar1;
  return iVar1 != 0;
}

