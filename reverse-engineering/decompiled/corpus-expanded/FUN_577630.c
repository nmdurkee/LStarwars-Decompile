/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x577630; label: FUN_00577630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00577630(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  FUN_005775b0();
  uVar1 = (uint)DAT_00951881;
  uVar3 = 0;
  if (uVar1 + 1 < (uint)DAT_00951880) {
    puVar4 = &DAT_00951500;
    do {
      puVar5 = &DAT_0095151c + uVar1 * 7;
      puVar6 = puVar4;
      for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      uVar3 = uVar3 + 1;
      uVar1 = DAT_00951881 + uVar3;
      puVar4 = puVar4 + 7;
    } while ((int)(uVar1 + 1) < (int)(uint)DAT_00951880);
  }
  DAT_00951880 = (byte)uVar3;
  _memset(&DAT_00951500 + (uVar3 & 0xff) * 7,0,(0x20 - (uVar3 & 0xff)) * 0x1c);
  DAT_00951881 = 0;
  _DAT_009518f0 = 0;
  return;
}

