/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x443500; label: FUN_00443500
 */

float10 FUN_00443500(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = -1;
  if ((param_4 != 0) && (param_1 != 0)) {
    iVar4 = 0;
    if (0 < DAT_0093b278) {
      iVar5 = 0;
      do {
        if (iVar3 != -1) break;
        iVar1 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0xc + DAT_0093b274),param_4);
        if (iVar1 == 0) {
          iVar3 = iVar4;
        }
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x4c;
      } while (iVar4 < DAT_0093b278);
    }
    iVar4 = 0;
    if (0 < DAT_0093d500) {
      puVar2 = (uint *)(DAT_0093d504 + 0x1fc);
      do {
        if (((((*puVar2 & 1) != 0) && ((*puVar2 & 0x1000) != 0)) && ((puVar2[-1] & 0x400) != 0)) &&
           (((short)puVar2[0x39a] == iVar3 &&
            (((puVar2[0x32a] == 0 || (puVar2[0x2b5] == 0)) ||
             (*(char *)(puVar2[0x2b5] + 0x7b5) != ';')))))) {
          return (float10)1;
        }
        iVar4 = iVar4 + 1;
        puVar2 = puVar2 + 0x436;
      } while (iVar4 < DAT_0093d500);
    }
  }
  return (float10)0;
}

