/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0800; label: FUN_005d0800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0800(short *param_1,undefined4 param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  sVar1 = *param_1;
  iVar4 = _rand();
  iVar4 = iVar4 % (int)sVar1;
  sVar2 = param_1[1];
  iVar3 = *(int *)(param_1 + 4);
  uVar5 = _rand();
  FUN_005b3d80(param_2,iVar3 + sVar2 * iVar4 * 0xc,
               iVar3 + ((iVar4 + 1) % (int)sVar1) * (int)sVar2 * 0xc,
               (float)(uVar5 & 0x7fff) * 3.0517578e-05);
  return;
}

