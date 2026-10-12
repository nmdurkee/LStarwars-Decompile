/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x5009d0; label: FUN_005009d0
 */

undefined4 FUN_005009d0(int param_1,int param_2)

{
  uint uVar1;
  
  if ((((*(byte *)(param_1 + 0x8c) & 0x80) == 0) || (param_2 != 0)) &&
     (*(int *)(param_1 + 0xec) == 0)) {
    uVar1 = *(uint *)(param_1 + 0x88);
    if ((uVar1 & 0x10000000) == 0) {
      *(uint *)(param_1 + 0x88) = uVar1 | 0x10000000;
      *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xbc);
    }
    else {
      *(uint *)(param_1 + 0x88) = uVar1 & 0xefffffff;
      *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xc0);
    }
    FUN_004fff20(*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x2c));
    return 1;
  }
  FUN_004fff20(*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x2c));
  return 0;
}

