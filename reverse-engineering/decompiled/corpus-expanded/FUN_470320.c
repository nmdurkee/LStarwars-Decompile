/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x470320; label: FUN_00470320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00470320(int param_1)

{
  int iVar1;
  
  *(byte *)(DAT_00879468 + 0x559) = *(byte *)(DAT_00879468 + 0x559) | 0x10;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(byte *)(DAT_00879468 + 0x559) = *(byte *)(DAT_00879468 + 0x559) & 0xef;
    }
  }
  return;
}

