/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x470260; label: FUN_00470260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00470260(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f9e70(param_1);
  if (iVar1 != 0) {
    *(undefined1 *)(DAT_00879468 + 0x562) = 1;
  }
  return;
}

