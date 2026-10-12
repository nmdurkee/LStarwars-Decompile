/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d7810; label: FUN_005d7810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d7810(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6,undefined4 *param_7,int param_8,int param_9)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  float local_11c;
  undefined4 *local_118;
  int local_114;
  float local_110;
  undefined4 local_10c;
  int local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_11c;
  local_11c = (float)(param_2 + -0x32) / (float)param_5;
  local_118 = param_7;
  local_114 = param_8;
  local_10c = FUN_006e6b90();
  _sprintf(local_104,
           "<TABLE bgColor=white height=16 width=%d cellSpacing=0 cellPadding=\"1\" border=1><TR><TD><Center>%s</Center></TD></TR></TABLE>\r\n"
           ,param_2 + 5,param_1);
  FUN_005d7230(local_104);
  _sprintf(local_104,
           "<TABLE bgColor=white height=%d width=%d cellSpacing=0 cellPadding=\"1\" border=1 VAlign=bottom><TR><TD>\r\n"
           ,param_3,param_2);
  FUN_005d7230(local_104);
  _sprintf(local_104,
           "<TABLE height=\"100%%%%\" width=%d cellSpacing=1 cellPadding=0 border=0 Align=left>\r\n"
           ,0x32);
  FUN_005d7230(local_104);
  local_110 = 80.0 / (float)param_6;
  iVar1 = param_6 + (param_6 >> 0x1f & 3U);
  iVar3 = 4;
  do {
    _sprintf(local_104,
             "<TR><TD valign=top align=right Height=\"%d%%%%\" bgColor=gray><DIV style=\"FONT-SIZE: 10pt\">%d</TD></TR>\r\n"
             ,0x14,param_6);
    FUN_005d7230(local_104);
    param_6 = param_6 - (iVar1 >> 2);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _sprintf(local_104,
           "<TR><TD valign=top align=right Height=\"%d%%%%\" bgColor=gray><DIV style=\"FONT-SIZE: 10pt\">%d</TD></TR>\r\n"
           ,0x14,0);
  FUN_005d7230(local_104);
  FUN_005d7230("</CENTER></TABLE>\r\n");
  local_11c = 0.0;
  if (0 < param_5) {
    local_108 = param_4 - (int)local_118;
    puVar4 = local_118;
    do {
      if ((local_114 == 0) || (param_9 == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(undefined4 *)(local_114 + (int)local_11c * 4);
        local_11c = (float)((int)local_11c + 1);
        if (param_9 <= (int)local_11c) {
          local_11c = 0.0;
        }
      }
      iVar1 = FUN_006e6b90();
      if (0x50 < iVar1) {
        iVar1 = 0x50;
      }
      _sprintf(local_104,
               "<TABLE height=\"100%%%%\" width=%d cellSpacing=1 cellPadding=0 border=0 Align=left><TR><TD></TD></TR>\r\n"
               ,local_10c);
      FUN_005d7230(local_104);
      _sprintf(local_104,"<TR><TD Height=\"%d%%%%\" bgColor=%06X></TD></TR>\r\n",iVar1,uVar5);
      FUN_005d7230(local_104);
      if ((local_118 == (undefined4 *)0x0) ||
         (puVar2 = (undefined2 *)*puVar4, puVar2 == (undefined2 *)0x0)) {
        puVar2 = &DAT_007596f8;
      }
      _sprintf(local_104,
               "<TR><TD Height=\"%d%%%%\" bgColor=lightgrey><DIV style=\"FONT-SIZE: 10pt; WIDTH: 10pt; WRITING-MODE: tb-rl\">%s</DIV></TD></TR></TABLE>\r\n"
               ,0x14,puVar2);
      FUN_005d7230(local_104);
      puVar4 = puVar4 + 1;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  FUN_005d7230("</TABLE></TD></tr></TABLE>\r\n");
  __security_check_cookie(local_4 ^ (uint)&local_11c);
  return;
}

