/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x4439b0; label: FUN_004439b0
 */

float10 FUN_004439b0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  float10 fVar2;
  undefined1 local_c [12];
  
  if ((((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) && (*(int *)(param_3 + 0xe4) != 0)) &&
     (iVar1 = *(int *)(*(int *)(param_3 + 0xe4) + 4), iVar1 != 0)) {
    fVar2 = (float10)FUN_005becc0(*(int *)(param_3 + 0xd0) + 0x5c,iVar1 + 0x170,local_c);
    return fVar2;
  }
  return (float10)(float)0x4e6e6b28;
}

