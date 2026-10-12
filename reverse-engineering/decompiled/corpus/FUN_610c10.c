/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x610c10; label: FUN_00610c10
 */

void FUN_00610c10(undefined4 param_1,int param_2)

{
  int in_ECX;
  
  *(char *)(*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x10)) = (char)param_2;
  *(char *)(*(int *)(in_ECX + 0xc) + 1 + *(int *)(in_ECX + 0x10)) = (char)((uint)param_2 >> 8);
  FUN_004ef660(*(int *)(in_ECX + 0xc) + 2 + *(int *)(in_ECX + 0x10),param_1,param_2);
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + param_2 + 2;
  return;
}

