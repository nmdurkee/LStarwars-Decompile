/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d7590; label: FUN_005d7590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d7590(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,undefined4 *param_7,int param_8,int param_9)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int local_11c;
  int local_118;
  undefined4 *local_114;
  float local_110;
  int local_10c;
  int local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_11c;
  local_114 = param_7;
  local_118 = param_4;
  local_108 = param_8;
  _sprintf(local_104,
           "<TABLE bgColor=white height=16 width=%d cellSpacing=0 cellPadding=\"1\" border=1><TR><TD><Center>%s</Center></TD></TR></TABLE>\r\n"
           ,param_2,param_1);
  FUN_005d7230(local_104);
  _sprintf(local_104,
           "<TABLE bgColor=white height=%d width=%d cellSpacing=0 cellPadding=0 border=1><tr><TD VAlign=top>\r\n"
           ,param_3,param_2);
  FUN_005d7230(local_104);
  local_10c = param_3 / (param_5 + 1);
  _sprintf(local_104,"<TABLE height=%d width=\"100%%%%\" cellSpacing=1 cellPadding=0 border=0 >\r\n"
           ,local_10c);
  FUN_005d7230(local_104);
  local_110 = 88.0 / (float)param_6;
  _sprintf(local_104,
           "<TD width=\"%d%%%%\" bgColor=gray Align=right><DIV style=\"FONT-SIZE: 10pt; WIDTH: 10pt;\">%d</DIV></TD>\r\n"
           ,0xc,0);
  FUN_005d7230(local_104);
  iVar4 = (int)(param_6 + (param_6 >> 0x1f & 3U)) >> 2;
  iVar2 = 4;
  iVar6 = iVar4;
  do {
    _sprintf(local_104,
             "<TD width=\"%d%%%%\" bgColor=gray Align=right><DIV style=\"FONT-SIZE: 10pt; WIDTH: 10pt;\">%d</DIV></TD>\r\n"
             ,0x16,iVar6);
    FUN_005d7230(local_104);
    iVar6 = iVar6 + iVar4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _sprintf(local_104,"</TD></tr></TABLE>\r\n\r\n");
  FUN_005d7230(local_104);
  local_11c = 0;
  if (0 < param_5) {
    local_118 = local_118 - (int)local_114;
    puVar3 = local_114;
    do {
      iVar6 = FUN_006e6b90();
      if (0x58 < iVar6) {
        iVar6 = 0x58;
      }
      if ((local_108 == 0) || (param_9 == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(undefined4 *)(local_108 + local_11c * 4);
        local_11c = local_11c + 1;
        if (param_9 <= local_11c) {
          local_11c = 0;
        }
      }
      _sprintf(local_104,
               "<TABLE height=%d width=\"100%%%%\" cellSpacing=1 cellPadding=0 border=0><TR>\r\n",
               local_10c);
      FUN_005d7230(local_104);
      if ((local_114 == (undefined4 *)0x0) ||
         (puVar1 = (undefined2 *)*puVar3, puVar1 == (undefined2 *)0x0)) {
        puVar1 = &DAT_007596f8;
      }
      _sprintf(local_104,
               "<TD align=right width=\"%d%%%%\" bgColor=lightgrey><DIV style=\"FONT-SIZE: 10pt\">%s</TD>\r\n"
               ,0xc,puVar1);
      FUN_005d7230(local_104);
      _sprintf(local_104,"<TD width=\"%d%%%%\" bgColor=%06X></TD>\r\n",iVar6,uVar5);
      FUN_005d7230(local_104);
      _sprintf(local_104,"<TD width=50 bgColor=white></TD></TR></TABLE>\r\n");
      FUN_005d7230(local_104);
      puVar3 = puVar3 + 1;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  _sprintf(local_104,"</TD></tr></TABLE>\r\n\r\n");
  FUN_005d7230(local_104);
  __security_check_cookie(local_4 ^ (uint)&local_11c);
  return;
}

