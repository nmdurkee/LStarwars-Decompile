/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69e700; label: FUN_0069e700
 */

/* WARNING: Removing unreachable block (ram,0x0069e7fe) */

int FUN_0069e700(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  longlong lVar4;
  undefined1 auStack_10 [16];
  
  uVar1 = unaff_ESI[2];
  uVar2 = unaff_ESI[3];
  if (((code *)unaff_ESI[0xb1] == (code *)0x0) || (unaff_ESI[0xb3] == 0)) {
    unaff_ESI[4] = 0xffffffff;
    unaff_ESI[5] = 0xffffffff;
    unaff_ESI[2] = 0xffffffff;
    unaff_ESI[3] = 0xffffffff;
  }
  else {
    (*(code *)unaff_ESI[0xb1])(*unaff_ESI,0,0,2);
    iVar3 = (*(code *)unaff_ESI[0xb3])(*unaff_ESI);
    unaff_ESI[5] = iVar3 >> 0x1f;
    unaff_ESI[4] = iVar3;
    unaff_ESI[2] = iVar3;
    unaff_ESI[3] = unaff_ESI[5];
  }
  if ((unaff_ESI[4] & unaff_ESI[5]) != 0xffffffff) {
    lVar4 = FUN_0069b3f0(auStack_10);
    if ((lVar4 < 0x100000000) && (lVar4 < 0)) {
      return (int)lVar4;
    }
    iVar3 = FUN_0069b2e0(0,0);
    if ((iVar3 == 0) && (iVar3 = FUN_0069b5e0(), iVar3 == 0)) {
      iVar3 = FUN_0069b700();
      if (iVar3 < 0) {
        return -0x80;
      }
      FUN_0069bbf0(uVar1,uVar2);
      iVar3 = FUN_0069c7a0();
    }
    return iVar3;
  }
  return -0x83;
}

