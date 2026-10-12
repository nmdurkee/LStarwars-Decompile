/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x622f00; label: FUN_00622f00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00622f00(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined1 local_128;
  char local_127;
  char local_126;
  char local_125;
  char local_124;
  char local_123;
  char local_122;
  undefined1 *local_120;
  byte local_11c [8];
  char local_114;
  char local_113;
  char local_112;
  char local_111;
  char local_110;
  char local_10e;
  char local_10c;
  char local_10b;
  char local_10a;
  char local_109;
  char local_108;
  char local_106;
  char local_104;
  char local_103;
  char local_102;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_128;
  local_120 = param_1;
  FUN_00622ad0(param_2);
  FUN_00622b50(param_3);
  puVar5 = &DAT_02900c88;
  PTR_DAT_0080fad0 = &DAT_02900c88;
  PTR_DAT_0080facc = &DAT_02900c88;
  DAT_02913050 = 0;
  DAT_02913054 = 0;
  DAT_02913058 = 0;
  if (DAT_02912f4c == '\0') {
    iVar2 = FUN_004ffc20(param_1);
    FUN_004ef660(&DAT_02900c88,s_D_______0080faf4,7);
    FUN_004f1f10(&DAT_02900c8f,&DAT_0076af24);
    DAT_02913058 = DAT_02913058 + 1;
    puVar5 = &DAT_02900c92;
    if (iVar2 != 0) {
      iVar3 = FUN_004ffd80(iVar2,local_11c);
      param_1 = local_120;
      while (local_120 = param_1, iVar3 != 0) {
        if (((local_104 != '.') ||
            ((local_103 != '\0' && ((local_103 != '.' || (local_102 != '\0')))))) &&
           ((local_11c[0] & 8) != 0)) {
          if ((undefined1 *)0x2910c87 < puVar5 + iVar3 + 8) break;
          local_124 = local_111 + 'A';
          local_125 = local_112 + 'A';
          local_126 = local_113 + 'A';
          local_127 = local_114 + 'A';
          local_123 = local_110 + 'A';
          local_122 = local_10e + -0x7b;
          local_128 = 0x44;
          FUN_004ef660(puVar5,&local_128,7);
          puVar5 = puVar5 + 7;
          FUN_004f1f10(puVar5,&local_104);
          puVar5[iVar3] = 0;
          puVar5 = puVar5 + iVar3 + 1;
          DAT_02913058 = DAT_02913058 + 1;
        }
        iVar3 = FUN_004ffd80(iVar2,local_11c);
        param_1 = local_120;
      }
    }
    FUN_00622bc0(&DAT_02900c92,puVar5,DAT_0080faf0);
    if (iVar2 != 0) {
      FUN_004ffd20(iVar2);
    }
    local_120 = puVar5;
    iVar2 = FUN_004ffc20(param_1);
    if (iVar2 != 0) {
      iVar3 = FUN_004ffd80(iVar2,local_11c);
      while (iVar3 != 0) {
        if (((local_11c[0] & 8) == 0) && (iVar4 = FUN_00622990(&local_104), iVar4 != 0)) {
          if ((undefined1 *)0x2910c87 < puVar5 + iVar3 + 8) break;
          local_124 = local_109 + 'A';
          local_125 = local_10a + 'A';
          local_126 = local_10b + 'A';
          local_127 = local_10c + 'A';
          local_123 = local_108 + 'A';
          local_122 = local_106 + -0x7b;
          local_128 = 0x46;
          FUN_004ef660(puVar5,&local_128,7);
          puVar5 = puVar5 + 7;
          FUN_004f1f10(puVar5,&local_104);
          puVar5[iVar3] = 0;
          puVar5 = puVar5 + iVar3 + 1;
          DAT_02913058 = DAT_02913058 + 1;
        }
        iVar3 = FUN_004ffd80(iVar2,local_11c);
      }
    }
    FUN_00622bc0(local_120,puVar5,DAT_0080faf0);
    if (iVar2 != 0) {
      FUN_004ffd20(iVar2);
    }
  }
  else {
    pcVar6 = &DAT_02910ca8;
    GetLogicalDriveStringsA(0x400,&DAT_02910ca8);
    cVar1 = DAT_02910ca8;
    while (cVar1 != '\0') {
      iVar2 = FUN_004f1ff0(pcVar6);
      local_127 = 'A';
      local_123 = 'A';
      local_126 = 'A';
      local_125 = 'A';
      local_124 = 'A';
      local_128 = 0x56;
      local_122 = '#';
      FUN_004ef660(puVar5,&local_128,7);
      puVar5 = puVar5 + 7;
      FUN_004f1f10(puVar5,pcVar6);
      puVar5[iVar2] = 0;
      DAT_02913058 = DAT_02913058 + 1;
      pcVar6 = pcVar6 + iVar2 + 1;
      puVar5 = puVar5 + iVar2 + 1;
      cVar1 = *pcVar6;
    }
    FUN_00622bc0(&DAT_02900c88,puVar5,0);
  }
  PTR_DAT_0080fac8 = puVar5;
  __security_check_cookie(local_4 ^ (uint)&local_128);
  return;
}

