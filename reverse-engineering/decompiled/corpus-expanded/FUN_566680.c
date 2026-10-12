/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566680; label: FUN_00566680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00566680(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    uVar4 = 1 << ((byte)iVar2 & 0x1f) & param_1;
    if (uVar4 != 0) {
      iVar3 = 0;
      do {
        if ((&DAT_00802f68)[iVar3 * 2] == uVar4) {
          uVar4 = (&DAT_00802f6c)[iVar3 * 2];
          goto LAB_005666b3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x20);
      uVar4 = 0;
LAB_005666b3:
      uVar1 = uVar1 | uVar4;
    }
    iVar2 = iVar2 + 1;
    if (0x1f < iVar2) {
      return uVar1;
    }
  } while( true );
}

