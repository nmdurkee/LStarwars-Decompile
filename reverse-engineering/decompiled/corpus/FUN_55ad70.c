/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x55ad70; label: FUN_0055ad70
 */

void FUN_0055ad70(int *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_124;
  if (param_1 != (int *)0x0) {
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | 4;
    if ((void *)param_1[1] != (void *)0x0) {
      _memset((void *)param_1[1],0,DAT_00802724);
    }
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffc;
    if (DAT_0093b268 != (int *)0x0) {
      _sprintf(local_104,"%s.giz",param_3);
      FUN_006211c0(1);
      iVar2 = FUN_00621270(local_104,0);
      if (iVar2 != 0) {
        FUN_006217e0();
        iVar2 = FUN_006217e0();
        while (iVar2 != 0) {
          if (0x20 < iVar2) {
            iVar2 = FUN_00559570();
          }
          local_124 = 0;
          local_120 = 0;
          local_11c = 0;
          local_118 = 0;
          local_114 = 0;
          local_110 = 0;
          local_10c = 0;
          local_108 = 0;
          FUN_006216f0(&local_124,iVar2);
          FUN_00559580(&local_124);
          iVar2 = FUN_006217e0();
          iVar3 = FUN_00559e20(param_1,&local_124);
          if ((((iVar3 < 0) || (iVar2 < 1)) || (*DAT_0093b268 <= iVar3)) ||
             ((pcVar1 = *(code **)(DAT_0093b268[2] + 0x8c + iVar3 * 0x9c), pcVar1 == (code *)0x0 ||
              (iVar3 = (*pcVar1)(param_2,*(undefined4 *)(*param_1 + iVar3 * 0x14 + 0x10)),
              iVar3 == 0)))) {
            FUN_00559580(&local_124);
            for (; iVar2 != 0; iVar2 = iVar2 + -1) {
              FUN_006218c0();
            }
          }
          else {
            FUN_00559580(&local_124);
          }
          iVar2 = FUN_006217e0();
        }
        FUN_006213e0();
      }
    }
    FUN_00559a20(param_2);
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffb;
  }
  __security_check_cookie(local_4 ^ (uint)&local_124);
  return;
}

