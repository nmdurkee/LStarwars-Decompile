/* Ghidra pseudocode, not original source.
 * ev_cf2ac3d06457ecccb228c84c214202b97dbe51dc177c28ee443aaf4c995f45e9
 * Entry: 0x5f7b40; label: FUN_005f7b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f7b40(undefined4 *param_1)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iStack_8;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar5 = 0;
    puVar4 = &DAT_00986f00;
    iVar3 = 0;
    while (puVar4 != param_1) {
      iVar3 = iVar3 + 0x30;
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 0xc;
      if (iVar3 == 0x600) {
        return;
      }
    }
    if (param_1[0xb] == -1) {
      piVar1 = (int *)(&DAT_00986f00)[iVar5 * 0xc];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        (&DAT_00986f00)[iVar5 * 0xc] = 0;
      }
      piVar1 = (int *)(&DAT_00986f28)[iVar5 * 0xc];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        (&DAT_00986f28)[iVar5 * 0xc] = 0;
      }
    }
    if (*(short *)((int)param_1 + 10) == 1) {
      fVar2 = 1.0;
    }
    else {
      fVar2 = 1.5;
    }
    iStack_8 = (int)(longlong)
                    ROUND((float)(int)((uint)*(ushort *)((int)param_1 + 6) *
                                       (uint)*(ushort *)(param_1 + 1) * -4) * fVar2);
    DAT_02854bc0 = DAT_02854bc0 + iStack_8;
    _memset(&DAT_00986f00 + iVar5 * 0xc,0,0x30);
    (&DAT_0280d7e0)[iVar5] = 0;
  }
  return;
}

