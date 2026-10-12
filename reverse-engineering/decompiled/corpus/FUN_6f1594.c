/* Ghidra analysis pseudocode, not original source.
 * ev_526838828e273a637259fe0c0b8910ed57fcbb113f7ca97b4fe0b36ecb2b0c42
 * Entry: 0x6f1594; label: __heap_init
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

