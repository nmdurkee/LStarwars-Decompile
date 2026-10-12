/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x481c10; label: FUN_00481c10
 */

void FUN_00481c10(void)

{
  float *pfVar1;
  float *pfVar2;
  undefined *puVar3;
  char *pcVar4;
  int iVar5;
  int unaff_ESI;
  float local_c;
  float local_8;
  float local_4;
  
  pcVar4 = &DAT_007fa37a;
  iVar5 = 0;
  do {
    if (*(char *)(unaff_ESI + 0x16) == *pcVar4) {
      *(char *)(unaff_ESI + 0x18) = (char)iVar5;
      break;
    }
    pcVar4 = pcVar4 + 0x20;
    iVar5 = iVar5 + 1;
  } while ((int)pcVar4 < 0x7fa43a);
  if (iVar5 == 6) {
    *(undefined1 *)(unaff_ESI + 0x18) = 2;
    *(undefined1 *)(unaff_ESI + 0x16) = DAT_007fa3ba;
  }
  *(undefined4 *)(unaff_ESI + 0x28) = 0x4479c000;
  pfVar1 = (float *)(unaff_ESI + 0x20);
  *(undefined4 *)(unaff_ESI + 0x24) = 0x4479c000;
  *pfVar1 = 999.0;
  pfVar2 = (float *)(unaff_ESI + 0x2c);
  *(undefined4 *)(unaff_ESI + 0x34) = 0xc479c000;
  iVar5 = 0;
  *(undefined4 *)(unaff_ESI + 0x30) = 0xc479c000;
  *pfVar2 = -999.0;
  do {
    if (iVar5 == 0) {
      puVar3 = &DAT_007fa37c;
    }
    else {
      puVar3 = &DAT_007fa388;
    }
    FUN_005b3620(&local_c,puVar3 + (uint)*(byte *)(unaff_ESI + 0x18) * 0x20,
                 *(undefined2 *)(unaff_ESI + 0x14));
    if (local_c < *pfVar1) {
      *pfVar1 = local_c;
    }
    if (*pfVar2 < local_c) {
      *pfVar2 = local_c;
    }
    if (local_8 < *(float *)(unaff_ESI + 0x24)) {
      *(float *)(unaff_ESI + 0x24) = local_8;
    }
    if (*(float *)(unaff_ESI + 0x30) < local_8) {
      *(float *)(unaff_ESI + 0x30) = local_8;
    }
    if (local_4 < *(float *)(unaff_ESI + 0x28)) {
      *(float *)(unaff_ESI + 0x28) = local_4;
    }
    if (*(float *)(unaff_ESI + 0x34) < local_4) {
      *(float *)(unaff_ESI + 0x34) = local_4;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  *pfVar1 = *pfVar1 - 0.05;
  *(float *)(unaff_ESI + 0x24) = *(float *)(unaff_ESI + 0x24) - 0.05;
  *(float *)(unaff_ESI + 0x28) = *(float *)(unaff_ESI + 0x28) - 0.05;
  *pfVar2 = *pfVar2 + 0.05;
  *(float *)(unaff_ESI + 0x30) = *(float *)(unaff_ESI + 0x30) + 0.05;
  *(float *)(unaff_ESI + 0x34) = *(float *)(unaff_ESI + 0x34) + 0.05;
  FUN_005b37d0(pfVar1,pfVar1,unaff_ESI + 8);
  FUN_005b37d0(pfVar2,pfVar2,unaff_ESI + 8);
  *(byte *)(unaff_ESI + 0x17) = *(byte *)(unaff_ESI + 0x17) | 3;
  return;
}

