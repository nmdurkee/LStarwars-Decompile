/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x470210; label: FUN_00470210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00470210(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = FUN_004f9e70(param_1);
  *(byte *)(DAT_00879468 + 0x559) =
       *(byte *)(DAT_00879468 + 0x559) ^ (cVar1 << 3 ^ *(byte *)(DAT_00879468 + 0x559)) & 8;
  return;
}

