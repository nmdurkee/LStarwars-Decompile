/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f6430; label: FUN_004f6430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f6430(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_EDX;
  bool bVar6;
  
  iVar3 = DAT_00916fd8;
  iVar4 = in_EDX * 2;
  bVar6 = SBORROW4(iVar4,DAT_0090f798);
  iVar2 = iVar4 - DAT_0090f798;
  sVar1 = (&DAT_0090f7a0)[in_EDX];
  if (DAT_0090f798 < iVar4) {
    (&DAT_0090f7a0)[in_EDX] = sVar1;
    return;
  }
  do {
    iVar5 = iVar4;
    if ((bVar6 != iVar2 < 0) &&
       (*(ushort *)(iVar3 + (short)(&DAT_0090f7a2)[iVar4] * 2) <
        *(ushort *)(iVar3 + (short)(&DAT_0090f7a0)[iVar4] * 2))) {
      iVar5 = iVar4 + 1;
    }
    if (*(ushort *)(iVar3 + sVar1 * 2) <= *(ushort *)(iVar3 + (short)(&DAT_0090f7a0)[iVar5] * 2))
    break;
    (&DAT_0090f7a0)[in_EDX] = (&DAT_0090f7a0)[iVar5];
    iVar4 = iVar5 * 2;
    bVar6 = SBORROW4(iVar4,DAT_0090f798);
    iVar2 = iVar4 - DAT_0090f798;
    in_EDX = iVar5;
  } while (iVar4 <= DAT_0090f798);
  (&DAT_0090f7a0)[in_EDX] = sVar1;
  return;
}

