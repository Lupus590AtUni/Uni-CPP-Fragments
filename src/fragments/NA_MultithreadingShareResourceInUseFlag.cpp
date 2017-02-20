//C++ psudocode
JumpLabel:
while(resourceIsFree == false);
enterCriticalSection();
  if(resourceIsFree == false)
  {
    leaveCriticalSection();
    jump(JumpLabel);
  }
  resourceIsFree = false;
leaveCriticalSection();

useResource();
resourceIsFree = true;

//alt
while(true)
{
  while(resourceIsFree == false);
  enterCriticalSection();
    if(resourceIsFree == false)
    {
      leaveCriticalSection();
      contine;
    }
    resourceIsFree = false;
  leaveCriticalSection();
  break;
}

useResource();
resourceIsFree = true;