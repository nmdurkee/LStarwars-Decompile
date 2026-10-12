/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d7b30; label: FUN_005d7b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d7b30(undefined4 param_1,int param_2,undefined4 param_3,int *param_4,int param_5,
                 int param_6,int param_7)

{
  int *piVar1;
  float fVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 extraout_ST0;
  float local_120;
  float local_11c;
  int local_118;
  float local_114;
  int local_110;
  int local_10c;
  int *local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_120;
  local_108 = param_4;
  local_110 = param_7;
  _sprintf(local_104,
           "<TABLE bgColor=white height=16 width=%d cellSpacing=0 cellPadding=\"1\" border=1><TR><TD><Center>%s</Center></TD></TR></TABLE>\r\n"
           ,param_2,param_1);
  FUN_005d7230(local_104);
  _sprintf(local_104,
           "<TABLE bgColor=white height=%d width=%d cellSpacing=0 cellPadding=0 border=1><tr><TD VAlign=top>\r\n"
           ,param_3,param_2);
  FUN_005d7230(local_104);
  _sprintf(local_104,"<TABLE height=10 width=\"100%%%%\" cellSpacing=0 cellPadding=0 border=0 >\r\n"
          );
  FUN_005d7230(local_104);
  local_120 = (float)param_2;
  fVar2 = (float)FUN_006e6b90();
  local_120 = fVar2;
  local_10c = FUN_006e6b90();
  uVar3 = FUN_006e6b90();
  local_120 = (float)((int)fVar2 * 4);
  local_114 = (float)(int)local_120 / (float)param_6;
  _sprintf(local_104,
           "<TD width=\"%d%%%%\" bgColor=gray Align=right><DIV style=\"FONT-SIZE: 10pt; WIDTH: 10pt;\">%d</DIV></TD>\r\n"
           ,0xc,0);
  FUN_005d7230(local_104);
  _DAT_0096e538 = (float)*param_4 * local_114;
  _DAT_0097159c = 0.0;
  _DAT_0096637c = (_DAT_0096e538 - _DAT_0096e538) * 0.125;
  iVar7 = (int)(param_6 + (param_6 >> 0x1f & 3U)) >> 2;
  DAT_0096e4ec = 8;
  local_118 = 1;
  iVar6 = 4;
  iVar8 = iVar7;
  _DAT_00971870 = _DAT_0096e538;
  local_120 = _DAT_0096e538;
  do {
    _sprintf(local_104,
             "<TD width=\"%d%%%%\" bgColor=gray Align=right><DIV style=\"FONT-SIZE: 10pt; WIDTH: 10pt;\">%d</DIV></TD>\r\n"
             ,uVar3,iVar8);
    FUN_005d7230(local_104);
    iVar8 = iVar8 + iVar7;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  _sprintf(local_104,"</TD></tr></TABLE>");
  FUN_005d7230(local_104);
  iVar8 = 0;
  if (0 < param_5) {
    do {
      if ((local_110 == 0) ||
         (puVar4 = *(undefined2 **)(local_110 + iVar8 * 4), puVar4 == (undefined2 *)0x0)) {
        puVar4 = &DAT_007596f8;
      }
      _sprintf(local_104,
               "<TABLE  BORDER=0 CELLPADDING=0 CELLSPACING=0><TD width=\"12%%%%\" height=30 bgColor=lightgrey> <DIV style=\"FONT-SIZE: 10pt\">%s</TD>\r\n"
               ,puVar4);
      FUN_005d7230(local_104);
      _sprintf(local_104,"<TD width=\"88%%%%\" bgColor=green>\r\n");
      FUN_005d7230(local_104);
      iVar6 = 0x10;
      do {
        local_11c = _DAT_0096e538;
        iVar9 = DAT_0096e4ec + -1;
        local_120 = _DAT_0096e538;
        _DAT_0097159c = _DAT_0097159c + 1.0;
        _DAT_0096e538 = _DAT_0096637c + _DAT_0096e538;
        DAT_0096e4ec = iVar9;
        iVar7 = FUN_006e6b90();
        iVar5 = FUN_006e6b90();
        local_120 = (float)(iVar7 - iVar5);
        if (iVar9 == 0) {
          piVar1 = local_108 + local_118;
          local_118 = local_118 + 1;
          DAT_0096e4ec = 0x10;
          _DAT_0096637c = ((float)*piVar1 * local_114 - _DAT_00971870) / 17.0;
          local_11c = _DAT_00971870;
          local_120 = _DAT_00971870;
          _DAT_0097159c = (float)((float10)_DAT_0097159c + extraout_ST0);
          _DAT_0096e538 = _DAT_00971870 + _DAT_0096637c;
          _DAT_00971870 = (float)*piVar1 * local_114;
          iVar7 = FUN_006e6b90();
          iVar5 = FUN_006e6b90();
          local_120 = (float)(iVar5 - iVar7);
          if (iVar8 + 1 == param_5) {
            _DAT_0096637c = 0.0;
          }
        }
        if ((int)local_120 < 0) {
          local_11c = (float)(int)local_120 + local_11c;
          fVar2 = (float)-(int)local_120;
        }
        else {
          fVar2 = local_120;
          if ((int)local_120 < 1) {
            fVar2 = 1.4013e-45;
          }
        }
        iVar7 = FUN_006e6b90();
        _sprintf(local_104,
                 "  <TABLE width=\"100%%%%\" BORDER=0 CELLPADDING=0 CELLSPACING=0> <TD width=%d height=2 bgColor=white></TD> <TD width=%d bgColor=black> </TD> <TD width=%d  bgColor=white> </TD></TABLE>\r\n"
                 ,iVar7,fVar2,(((param_2 - iVar7) - (int)fVar2) - local_10c) + -4);
        FUN_005d7230(local_104);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      _sprintf(local_104,"<TR></TD> </TD></TABLE> \r\n\r\n");
      FUN_005d7230(local_104);
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_5);
  }
  _sprintf(local_104,"</TABLE>");
  FUN_005d7230(local_104);
  __security_check_cookie(local_4 ^ (uint)&local_120);
  return;
}

