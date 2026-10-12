/* Ghidra pseudocode, not original source.
 * ev_97f9900fcd0ba7492838edfd98b0150dba956191b40272664bd26bb1f92bea67
 * Entry: 0x6f1594; label: __heap_init
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 2005 Release */

int __cdecl __heap_init(void)

{
  int iVar1;
  int in_stack_00000004;
  
  DAT_0297c974 = HeapCreate((uint)(in_stack_00000004 == 0),0x1000,0);
  if (DAT_0297c974 == (HANDLE)0x0) {
    return 0;
  }
  DAT_029a9b28 = ___heap_select();
  if ((DAT_029a9b28 == 3) && (iVar1 = ___sbh_heap_init(0x3f8), iVar1 == 0)) {
    HeapDestroy(DAT_0297c974);
    DAT_0297c974 = (HANDLE)0x0;
    return 0;
  }
  return 1;
}

