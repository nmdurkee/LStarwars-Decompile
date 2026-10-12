/* Ghidra analysis pseudocode, not original source.
 * ev_89d123adc6bf396b2f6b4ec3563e25957edd0c204114ec20eecbaddaafaf9a77
 * Entry: 0x6f195e; label: ___sbh_heap_init
 */

/* Library Function - Single Match
    ___sbh_heap_init
   
   Library: Visual Studio 2005 Release */

undefined4 ___sbh_heap_init(undefined4 param_1)

{
  DAT_029a9b14 = HeapAlloc(DAT_0297c974,0,0x140);
  if (DAT_029a9b14 == (LPVOID)0x0) {
    return 0;
  }
  DAT_0297cac8 = 0;
  DAT_029a9b10 = 0;
  DAT_029a9b1c = DAT_029a9b14;
  DAT_029a9b18 = param_1;
  DAT_029a9b20 = 0x10;
  return 1;
}

