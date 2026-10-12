/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d3b90; label: FUN_006d3b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d3b90(undefined4 param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  undefined1 auVar3 [4];
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  byte *pbVar8;
  undefined2 *puVar9;
  int iVar10;
  byte local_210 [4];
  int local_20c;
  undefined1 local_208 [4];
  char local_204 [16];
  char local_1f4 [240];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_210;
  local_208 = (undefined1  [4])param_1;
  _sprintf(local_204,"\t\"%s\",\t0x%x,%d,%d, {",param_2,*(undefined4 *)(param_2 + 0x40),
           *(undefined4 *)(param_2 + 0x44),*(undefined4 *)(param_2 + 0x48));
  local_20c = 0;
  do {
    bVar1 = *(byte *)(local_20c + 0x4c + param_2);
    if (bVar1 < 0x20) {
      _sprintf(local_104,"%d",(uint)bVar1);
      pcVar4 = local_104;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      uVar5 = (int)pcVar4 - (int)local_104;
      pcVar4 = local_208 + 3;
      do {
        pcVar7 = pcVar4 + 1;
        pcVar4 = pcVar4 + 1;
      } while (*pcVar7 != '\0');
    }
    else {
      local_210[1] = 0;
      local_210[0] = bVar1;
      _sprintf(local_104,"\'%s\'",local_210);
      pcVar4 = local_104;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      uVar5 = (int)pcVar4 - (int)local_104;
      pcVar4 = local_208 + 3;
      do {
        pcVar7 = pcVar4 + 1;
        pcVar4 = pcVar4 + 1;
      } while (*pcVar7 != '\0');
    }
    auVar3 = local_208;
    pcVar7 = local_104;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar4 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar4 = pcVar4 + 1;
    }
    if (local_20c < 7) {
      puVar9 = (undefined2 *)(local_208 + 3);
      do {
        pcVar4 = (char *)((int)puVar9 + 1);
        puVar9 = (undefined2 *)((int)puVar9 + 1);
      } while (*pcVar4 != '\0');
      *puVar9 = 0x2c;
    }
    else {
      pcVar4 = local_208 + 3;
      do {
        pcVar7 = pcVar4;
        pcVar4 = pcVar7 + 1;
      } while (pcVar7[1] != '\0');
      builtin_strncpy(pcVar7 + 1,"}, //Guid stuff\n",0x11);
    }
    local_20c = local_20c + 1;
  } while (local_20c < 8);
  FUN_004f1f10(local_208,local_204);
  _sprintf(local_204,"\t%d,%d,%d,%d,%d,%d,0,0,\t//NumButtons etc.\n",(int)*(short *)(param_2 + 0x54)
           ,(int)*(short *)(param_2 + 0x56),(int)*(short *)(param_2 + 0x58),
           (int)*(short *)(param_2 + 0x5a),(int)*(short *)(param_2 + 0x5c),
           (int)*(short *)(param_2 + 0x5e));
  FUN_004f1e80(auVar3,local_204);
  FUN_004f1f10(local_204,&DAT_00775790);
  pbVar8 = (byte *)(param_2 + 0x65);
  iVar10 = 4;
  do {
    _sprintf(local_104,"%s,%d,%d, ",(&PTR_s_NOTSET_00825ec0)[pbVar8[-1]],(uint)*pbVar8,
             (uint)pbVar8[1]);
    FUN_004f1e80(local_204,local_104);
    pbVar8 = pbVar8 + 3;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  FUN_004f1e80(local_204,"//analogue thumb sticks\n");
  FUN_004f1e80(auVar3,local_204);
  FUN_004f1f10(local_204,&DAT_00775790);
  pbVar8 = (byte *)(param_2 + 0x71);
  iVar10 = 4;
  do {
    _sprintf(local_104,"%s,%d,%d, ",(&PTR_s_NOTSET_00825ec0)[pbVar8[-1]],(uint)*pbVar8,
             (uint)pbVar8[1]);
    FUN_004f1e80(local_204,local_104);
    pbVar8 = pbVar8 + 3;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  FUN_004f1e80(local_204,"//analogue shoulder buttons\n");
  FUN_004f1e80(auVar3,local_204);
  FUN_004f1f10(local_204,&DAT_00775790);
  pbVar8 = (byte *)(param_2 + 0x7c);
  iVar10 = 4;
  do {
    _sprintf(local_104,"%s,%d, ",(&PTR_s_NOTSET_00825ec0)[*pbVar8],(uint)pbVar8[1]);
    FUN_004f1e80(local_204,local_104);
    pbVar8 = pbVar8 + 2;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  FUN_004f1e80(local_204,"//l2,r2,l1,r1\n");
  FUN_004f1e80(auVar3,local_204);
  FUN_004f1f10(local_204,&DAT_00775790);
  pbVar8 = (byte *)(param_2 + 0x84);
  iVar10 = 4;
  do {
    _sprintf(local_104,"%s,%d, ",(&PTR_s_NOTSET_00825ec0)[*pbVar8],(uint)pbVar8[1]);
    FUN_004f1e80(local_204,local_104);
    pbVar8 = pbVar8 + 2;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  FUN_004f1e80(local_204,"//rup,rright,rdown,rleft\n");
  FUN_004f1e80(auVar3,local_204);
  FUN_004f1f10(local_204,&DAT_00775790);
  pbVar8 = (byte *)(param_2 + 0x8c);
  iVar10 = 4;
  do {
    _sprintf(local_104,"%s,%d, ",(&PTR_s_NOTSET_00825ec0)[*pbVar8],(uint)pbVar8[1]);
    FUN_004f1e80(local_204,local_104);
    pbVar8 = pbVar8 + 2;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  FUN_004f1e80(local_204,"//select,l3,r3,start\n");
  FUN_004f1e80(auVar3,local_204);
  FUN_004f1f10(local_204,&DAT_00775790);
  pbVar8 = (byte *)(param_2 + 0x94);
  iVar10 = 4;
  do {
    _sprintf(local_104,"%s,%d, ",(&PTR_s_NOTSET_00825ec0)[*pbVar8],(uint)pbVar8[1]);
    FUN_004f1e80(local_204,local_104);
    pbVar8 = pbVar8 + 2;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  FUN_004f1e80(local_204,"//lup,lright,ldown,lleft\n");
  FUN_004f1e80(auVar3,local_204);
  __security_check_cookie(local_4 ^ (uint)local_210);
  return;
}

