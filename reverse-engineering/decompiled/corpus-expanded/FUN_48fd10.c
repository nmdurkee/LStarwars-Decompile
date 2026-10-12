/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48fd10; label: FUN_0048fd10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0048fd10(int param_1)

{
  ushort *puVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  
  if (*(int *)(param_1 + 0x506c) != 0) {
    return 0;
  }
  iVar5 = FUN_006217e0();
  iVar6 = FUN_006217e0();
  iVar7 = 0;
  *(int *)(param_1 + 0x506c) = iVar6;
  if (0 < iVar6) {
    iVar6 = 0;
    do {
      FUN_006216f0(iVar6 + 0x58 + *(int *)(param_1 + 0x5068),0x10);
      FUN_00621900(iVar6 + 0x68 + *(int *)(param_1 + 0x5068));
      uVar4 = FUN_00621860();
      *(undefined2 *)(iVar6 + 0x88 + *(int *)(param_1 + 0x5068)) = uVar4;
      uVar2 = FUN_006218c0();
      *(undefined1 *)(iVar6 + 0x96 + *(int *)(param_1 + 0x5068)) = uVar2;
      if (1 < iVar5) {
        bVar3 = FUN_006218c0();
        *(ushort *)(iVar6 + 0x94 + *(int *)(param_1 + 0x5068)) =
             (short)(char)(bVar3 & 1) << 5 |
             *(ushort *)(iVar6 + 0x94 + *(int *)(param_1 + 0x5068)) & 0xffdf;
      }
      if (iVar5 < 3) {
        *(undefined4 *)(iVar6 + 0x80 + *(int *)(param_1 + 0x5068)) = 0x40000000;
      }
      else {
        fVar8 = (float10)FUN_006217a0();
        *(float *)(iVar6 + 0x80 + *(int *)(param_1 + 0x5068)) = (float)fVar8;
      }
      if (iVar5 < 4) {
        puVar1 = (ushort *)(iVar6 + 0x94 + *(int *)(param_1 + 0x5068));
        *puVar1 = *puVar1 & 0xfeff;
      }
      else {
        bVar3 = FUN_006218c0();
        *(ushort *)(iVar6 + 0x94 + *(int *)(param_1 + 0x5068)) =
             (bVar3 & 1) << 8 | *(ushort *)(iVar6 + 0x94 + *(int *)(param_1 + 0x5068)) & 0xfeff;
      }
      if (iVar5 < 5) {
        *(undefined4 *)(iVar6 + 0x50 + *(int *)(param_1 + 0x5068)) = 0;
        *(undefined4 *)(iVar6 + 0x4c + *(int *)(param_1 + 0x5068)) = 0;
        *(undefined4 *)(iVar6 + 0x54 + *(int *)(param_1 + 0x5068)) = 0xbe138ef3;
        *(undefined4 *)(iVar6 + 0x84 + *(int *)(param_1 + 0x5068)) = 0x3f800000;
      }
      else {
        FUN_00621900(iVar6 + 0x4c + *(int *)(param_1 + 0x5068));
        fVar8 = (float10)FUN_006217a0();
        *(float *)(iVar6 + 0x84 + *(int *)(param_1 + 0x5068)) = (float)fVar8;
      }
      if (5 < iVar5) {
        bVar3 = FUN_006218c0();
        *(ushort *)(iVar6 + 0x94 + *(int *)(param_1 + 0x5068)) =
             (short)(char)(bVar3 & 1) << 9 |
             *(ushort *)(iVar6 + 0x94 + *(int *)(param_1 + 0x5068)) & 0xfdff;
      }
      *(undefined2 *)(iVar6 + 0x8c + *(int *)(param_1 + 0x5068)) = 0xffff;
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 0xa0;
    } while (iVar7 < *(int *)(param_1 + 0x506c));
  }
  return 1;
}

