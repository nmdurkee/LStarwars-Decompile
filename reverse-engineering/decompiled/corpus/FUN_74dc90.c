/* Ghidra analysis pseudocode, not original source.
 * ev_7c321bc51ff35622de6c5d479df857df6f5bf01a82339419049d6b39c5416ee3
 * Entry: 0x74dc90; label: FUN_0074dc90
 */

/* WARNING: Removing unreachable block (ram,0x0074dce1) */

void FUN_0074dc90(byte *param_1)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int in_ECX;
  byte *pbVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined4 *local_210;
  byte *local_20c;
  int local_208;
  undefined1 local_204 [256];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_210;
  local_208 = in_ECX + 0x100;
  puVar9 = *(undefined4 **)(in_ECX + 0x104);
  local_20c = param_1;
  if (*(undefined4 **)(in_ECX + 0x108) < puVar9) {
    FUN_006e9fe6();
  }
  do {
    puVar6 = *(undefined4 **)(in_ECX + 0x108);
    if (puVar6 < *(undefined4 **)(in_ECX + 0x104)) {
      FUN_006e9fe6();
    }
    if (puVar6 <= puVar9) {
      iVar4 = 0;
      local_210 = (undefined4 *)0x0;
      cVar2 = FUN_0074b640(in_ECX,&local_210,local_204);
      if (cVar2 == '\0') goto LAB_0074dda9;
      iVar4 = 0;
      break;
    }
    if (*(undefined4 **)(in_ECX + 0x108) <= puVar9) {
      FUN_006e9fe6();
    }
    pbVar3 = *(byte **)*puVar9;
    pbVar8 = local_20c;
    do {
      bVar1 = *pbVar3;
      bVar10 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_0074dd20:
        iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_0074dd25;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar10 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_0074dd20;
      pbVar3 = pbVar3 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_0074dd25:
    if (iVar4 == 0) goto LAB_0074de25;
    if (*(undefined4 **)(in_ECX + 0x108) <= puVar9) {
      FUN_006e9fe6();
    }
    puVar9 = puVar9 + 1;
  } while( true );
  while( true ) {
    _sprintf(local_104,"%s\\%s",local_204,local_20c);
    iVar4 = FUN_004fa5f0(local_104,0);
    cVar2 = FUN_0074b640(in_ECX,&local_210,local_204);
    if (cVar2 == '\0') break;
    if (iVar4 != 0) break;
  }
LAB_0074dda9:
  iVar5 = FUN_004f6b40(iVar4);
  if (0 < iVar5) {
    puVar6 = (undefined4 *)FUN_006ea018(0x14);
    puVar9 = (undefined4 *)0x0;
    if (puVar6 != (undefined4 *)0x0) {
      pcVar7 = __strdup((char *)local_20c);
      *puVar6 = pcVar7;
      FUN_00748430(iVar5,1);
      puVar9 = puVar6;
    }
    local_210 = puVar9;
    if ((int)puVar9[3] < iVar5) {
      FUN_007484e0(iVar5);
    }
    puVar9[2] = iVar5;
    FUN_0074dc20(&local_210);
    FUN_004fb550(iVar4,puVar9[1],puVar9[2]);
    FUN_004f99e0(iVar4);
  }
LAB_0074de25:
  __security_check_cookie(local_4 ^ (uint)&local_210);
  return;
}

