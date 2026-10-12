/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5daae0; label: FUN_005daae0
 */

void FUN_005daae0(int param_1,byte param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = (uint)*(byte *)(*(int *)(param_1 + 0x18c) + (uint)param_2) * 0x50 +
          *(int *)(param_1 + 0x184);
  FUN_005c0500(param_5,iVar1,(uint)*(byte *)(iVar1 + 0x44) * 0x40 + param_4);
  FUN_005c0500(param_5,param_5,param_3);
  return;
}

