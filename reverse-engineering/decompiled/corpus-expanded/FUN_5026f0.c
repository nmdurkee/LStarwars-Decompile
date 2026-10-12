/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x5026f0; label: FUN_005026f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005026f0(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *unaff_EDI;
  
  uVar5 = 0;
  if ((short)unaff_EDI[1] != 0) {
    iVar6 = 0;
    iVar4 = 0;
    do {
      iVar2 = *param_1;
      iVar3 = *unaff_EDI;
      *(undefined1 *)(iVar2 + iVar6 + 0xc) = 0;
      bVar1 = *(byte *)(iVar3 + iVar4 + 0x58);
      if (((bVar1 & 4) != 0) && ((bVar1 & 2) != 0)) {
        *(byte *)(iVar2 + iVar6 + 0xd) = bVar1 & 1;
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x5c;
      iVar6 = iVar6 + 0x10;
    } while (uVar5 < *(ushort *)(unaff_EDI + 1));
  }
  return;
}

