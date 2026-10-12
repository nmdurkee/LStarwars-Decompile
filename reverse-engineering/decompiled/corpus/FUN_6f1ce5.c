/* Ghidra analysis pseudocode, not original source.
 * ev_89d123adc6bf396b2f6b4ec3563e25957edd0c204114ec20eecbaddaafaf9a77
 * Entry: 0x6f1ce5; label: ___sbh_alloc_new_region
 */

/* Library Function - Single Match
    ___sbh_alloc_new_region
   
   Library: Visual Studio 2005 Release */

undefined4 * ___sbh_alloc_new_region(void)

{
  LPVOID pvVar1;
  undefined4 *puVar2;
  
  if (DAT_029a9b10 == DAT_029a9b20) {
    pvVar1 = HeapReAlloc(DAT_0297c974,0,DAT_029a9b14,(DAT_029a9b20 + 0x10) * 0x14);
    if (pvVar1 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_029a9b20 = DAT_029a9b20 + 0x10;
    DAT_029a9b14 = pvVar1;
  }
  puVar2 = (undefined4 *)(DAT_029a9b10 * 0x14 + (int)DAT_029a9b14);
  pvVar1 = HeapAlloc(DAT_0297c974,8,0x41c4);
  puVar2[4] = pvVar1;
  if (pvVar1 != (LPVOID)0x0) {
    pvVar1 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar2[3] = pvVar1;
    if (pvVar1 != (LPVOID)0x0) {
      puVar2[2] = 0xffffffff;
      *puVar2 = 0;
      puVar2[1] = 0;
      DAT_029a9b10 = DAT_029a9b10 + 1;
      *(undefined4 *)puVar2[4] = 0xffffffff;
      return puVar2;
    }
    HeapFree(DAT_0297c974,0,(LPVOID)puVar2[4]);
  }
  return (undefined4 *)0x0;
}

