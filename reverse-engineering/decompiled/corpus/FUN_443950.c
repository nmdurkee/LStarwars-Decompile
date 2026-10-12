/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443950; label: FUN_00443950
 */

float10 FUN_00443950(int param_1,undefined4 param_2,int param_3)

{
  float10 fVar1;
  undefined1 local_c [12];
  
  if ((((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) && (*(int *)(param_3 + 0xe4) != 0)) &&
     ((param_1 != 0 && (*(int *)(param_1 + 0x138c) != 0)))) {
    fVar1 = (float10)FUN_005becc0(*(int *)(param_1 + 0x138c) + 0x5c,*(int *)(param_3 + 0xe4) + 0x5c,
                                  local_c);
    return fVar1;
  }
  return (float10)(float)0x4e6e6b28;
}

