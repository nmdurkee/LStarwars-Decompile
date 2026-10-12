/* Ghidra pseudocode, not original source.
 * ev_97f9900fcd0ba7492838edfd98b0150dba956191b40272664bd26bb1f92bea67
 * Entry: 0x6f0d9d; label: __wincmdln
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __wincmdln
   
   Library: Visual Studio 2005 Release */

byte * __wincmdln(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  byte *pbVar4;
  
  bVar2 = false;
  if (DAT_029a9c58 == 0) {
    ___initmbctable();
  }
  pbVar4 = DAT_029aac84;
  if (DAT_029aac84 == (byte *)0x0) {
    pbVar4 = &DAT_007516c0;
  }
  do {
    bVar1 = *pbVar4;
    if (bVar1 < 0x21) {
      if (bVar1 == 0) {
        return pbVar4;
      }
      if (!bVar2) {
        for (; (*pbVar4 != 0 && (*pbVar4 < 0x21)); pbVar4 = pbVar4 + 1) {
        }
        return pbVar4;
      }
    }
    if (bVar1 == 0x22) {
      bVar2 = !bVar2;
    }
    iVar3 = __ismbblead((uint)bVar1);
    if (iVar3 != 0) {
      pbVar4 = pbVar4 + 1;
    }
    pbVar4 = pbVar4 + 1;
  } while( true );
}

