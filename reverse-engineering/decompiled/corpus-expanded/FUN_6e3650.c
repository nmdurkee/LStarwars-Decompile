/* Ghidra pseudocode, not original source.
 * ev_bed396bb9d0ac343cc12a945b22dca9b47e381958104004b469ab6f75949f391
 * Entry: 0x6e3650; label: FUN_006e3650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e3650(void)

{
  ushort uVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  
  FUN_006e2880(0,*(undefined4 *)(in_ECX + 0x6b0));
  *(undefined4 *)(in_ECX + 0x6e8) = *(undefined4 *)(in_ECX + 0x6b0);
  iVar3 = 1;
  piVar2 = (int *)(in_ECX + 0x6f4);
  do {
    if ((*(int *)(in_ECX + 0x638) == 0) && (1 < DAT_02974d1c)) {
      uVar1 = *(ushort *)(in_ECX + 0xf8);
    }
    else {
      uVar1 = 1;
    }
    if ((iVar3 <= (int)(uVar1 - 1)) && (*piVar2 != 0)) {
      *piVar2 = 0;
      (**(code **)(**(int **)(in_ECX + 4) + 0x94))(*(int **)(in_ECX + 4),iVar3,0);
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar3 != 4);
  (**(code **)(**(int **)(in_ECX + 4) + 0x9c))
            (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x6ec));
  DAT_00973900 = *(int *)(in_ECX + 0x138);
  DAT_00973904 = *(int *)(in_ECX + 0x13c);
  _DAT_0080202c = DAT_00973900 / 2;
  _DAT_00802030 = DAT_00973904 / 2;
  FUN_006e2510();
  return;
}

