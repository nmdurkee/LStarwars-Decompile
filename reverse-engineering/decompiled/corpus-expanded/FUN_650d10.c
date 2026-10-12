/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x650d10; label: FUN_00650d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00650d10(int param_1,int param_2)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (uint)*(short *)(&DAT_02920d8a + param_1 * 8);
  sVar1 = (&DAT_02920d88)[param_1 * 4];
  if (param_2 == 0) {
    _DAT_00810364 = FUN_005b9e10(&DAT_00810364);
    if (uVar4 == 0) {
      uVar4 = 1;
    }
    uVar3 = (_DAT_00810364 >> 0x10) % uVar4;
  }
  else {
    uVar3 = (uint)*(short *)(&DAT_02920d8c + param_1 * 8);
    sVar2 = *(short *)(&DAT_02920d8c + param_1 * 8) + 1;
    *(short *)(&DAT_02920d8c + param_1 * 8) = sVar2;
    if ((int)uVar4 <= (int)sVar2) {
      *(short *)(&DAT_02920d8c + param_1 * 8) = 0;
      return (int)*(short *)(&DAT_02921260 + (uVar3 + (int)sVar1) * 2);
    }
  }
  return (int)*(short *)(&DAT_02921260 + (uVar3 + (int)sVar1) * 2);
}

