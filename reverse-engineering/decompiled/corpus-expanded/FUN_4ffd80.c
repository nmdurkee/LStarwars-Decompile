/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ffd80; label: FUN_004ffd80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ffd80(int param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  uint *puVar5;
  int iVar6;
  int extraout_EDX;
  undefined8 uVar7;
  uint local_148 [2];
  uint local_140;
  undefined1 local_13b;
  undefined1 local_13a;
  undefined1 local_139;
  undefined1 local_138;
  undefined1 local_137;
  byte local_136;
  byte local_135;
  undefined1 local_12b;
  undefined1 local_12a;
  undefined1 local_129;
  undefined1 local_128;
  undefined1 local_127;
  byte local_126;
  byte local_125;
  char local_108 [260];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_148;
  if (param_1 < 0x1000) {
    uVar7 = FUN_004ff7a0(param_1 + -1,local_148);
    iVar6 = (int)((ulonglong)uVar7 >> 0x20);
    iVar3 = (int)uVar7;
    if (iVar3 < 1) {
      if (iVar3 < 0) {
        FUN_004fe650(iVar3);
        iVar6 = extraout_EDX;
      }
    }
    else {
      *param_2 = (((local_148[0] >> 2 & 0x800 | local_148[0] & 0x100) >> 2 | local_148[0] & 0x80) >>
                  2 | local_148[0] & 0x40) >> 4;
      param_2[1] = local_140;
      *(undefined1 *)(param_2 + 2) = local_13b;
      *(undefined1 *)((int)param_2 + 10) = local_139;
      *(undefined1 *)((int)param_2 + 9) = local_13a;
      *(undefined1 *)((int)param_2 + 0xb) = local_138;
      *(undefined1 *)(param_2 + 3) = local_137;
      *(undefined1 *)(param_2 + 4) = local_12b;
      *(ushort *)((int)param_2 + 0xe) = (ushort)local_135 * 0x100 + (ushort)local_136;
      *(undefined1 *)((int)param_2 + 0x12) = local_129;
      *(undefined1 *)((int)param_2 + 0x13) = local_128;
      *(undefined1 *)((int)param_2 + 0x11) = local_12a;
      *(undefined1 *)(param_2 + 5) = local_127;
      *(ushort *)((int)param_2 + 0x16) = (ushort)local_125 * 0x100 + (ushort)local_126;
      puVar5 = param_2 + 6;
      pcVar4 = local_108;
      iVar6 = (int)puVar5 - (int)pcVar4;
      do {
        cVar1 = *pcVar4;
        pcVar4[iVar6] = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      iVar6 = (int)param_2 + 0x19;
      do {
        uVar2 = *puVar5;
        puVar5 = (uint *)((int)puVar5 + 1);
      } while ((char)uVar2 != '\0');
    }
    __security_check_cookie(local_4 ^ (uint)local_148,iVar6);
    return;
  }
  FUN_006def60(param_1 + -0x1000,param_2);
  __security_check_cookie(local_4 ^ (uint)local_148);
  return;
}

