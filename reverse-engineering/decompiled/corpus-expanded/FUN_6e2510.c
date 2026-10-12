/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e2510; label: FUN_006e2510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e2510(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 0x170);
  *piVar1 = 0;
  *(undefined4 *)(in_ECX + 0x174) = 0;
  *(undefined4 *)(in_ECX + 0x178) = DAT_00973900;
  uVar4 = DAT_00973904;
  *(undefined4 *)(in_ECX + 0x180) = 0;
  *(undefined4 *)(in_ECX + 0x184) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x17c) = uVar4;
  FUN_005dabf0(0,0x3f800000);
  fVar2 = (float)*(int *)(in_ECX + 0x174);
  if (*(int *)(in_ECX + 0x174) < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  fVar3 = (float)*piVar1;
  if (*piVar1 < 0) {
    fVar3 = fVar3 + 4.2949673e+09;
  }
  FUN_005ef9a0(fVar3 * 16.0,fVar2 * 16.0);
  FUN_005dae80(0x44200000,0x43600000);
  FUN_005ff390();
  *piVar1 = 0;
  *(undefined4 *)(in_ECX + 0x174) = 0;
  *(undefined4 *)(in_ECX + 0x178) = DAT_00973900;
  uVar4 = DAT_00973904;
  *(undefined4 *)(in_ECX + 0x180) = 0;
  *(undefined4 *)(in_ECX + 0x184) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x17c) = uVar4;
  FUN_006e57b0(piVar1);
  return;
}

