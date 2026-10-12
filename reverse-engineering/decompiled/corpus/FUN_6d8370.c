/* Ghidra analysis pseudocode, not original source.
 * ev_ce999f6f93348d1bea0c268e5ec4785c76bf2f100732e1944453dc4f4dda8e73
 * Entry: 0x6d8370; label: FUN_006d8370
 */

uint FUN_006d8370(int param_1,uint param_2)

{
  int in_ECX;
  int iVar1;
  
  if (param_1 - 10U < 4) {
    param_2 = 0;
  }
  iVar1 = DAT_029755a1 * 0x100;
  if ((&DAT_029751bc)[iVar1] != '\0') {
    param_2 = param_2 | 0x40;
  }
  if (*(char *)(in_ECX + 0x6334) != '\0') {
    param_2 = param_2 | 0x40;
  }
  if ((&DAT_0297523c)[iVar1] != '\0') {
    param_2 = param_2 | 0x40;
  }
  if ((&DAT_029751d9)[iVar1] != '\0') {
    param_2 = param_2 | 0x40;
  }
  if (*(char *)(in_ECX + 0x6336) != '\0') {
    param_2 = param_2 | 0x40;
  }
  if (*(char *)(in_ECX + 0x4e12) == '\0') {
    if (param_1 - 10U < 4) {
      param_2 = param_2 & 0xfffff7ff;
    }
    if ((&DAT_029751a1)[iVar1] != '\0') {
      param_2 = param_2 | 0x20;
    }
  }
  if ((&DAT_029751ae)[iVar1] != '\0') {
    param_2 = param_2 | 0x20;
  }
  if (*(char *)(in_ECX + 0x6335) != '\0') {
    param_2 = param_2 | 0x20;
  }
  if ((&DAT_029751db)[iVar1] != '\0') {
    param_2 = param_2 | 0x80;
  }
  if ((&DAT_029751dc)[iVar1] != '\0') {
    param_2 = param_2 | 0x10;
  }
  if ((&DAT_0297526d)[iVar1] != '\0') {
    param_2 = param_2 | 0x2000;
  }
  if ((&DAT_0297526b)[iVar1] != '\0') {
    param_2 = param_2 | 0x8000;
  }
  if ((&DAT_02975270)[iVar1] != '\0') {
    param_2 = param_2 | 0x4000;
  }
  if (*(float *)(in_ECX + 0x631c) < 0.0) {
    param_2 = param_2 | 0x4000;
  }
  if ((&DAT_02975268)[iVar1] != '\0') {
    param_2 = param_2 | 0x1000;
  }
  if (0.0 < *(float *)(in_ECX + 0x631c)) {
    param_2 = param_2 | 0x1000;
  }
  return param_2;
}

